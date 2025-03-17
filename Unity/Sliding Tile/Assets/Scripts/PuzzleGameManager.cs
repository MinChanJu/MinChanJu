using System.Collections.Generic;
using System.Text;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class PuzzleGameManager : MonoBehaviour
{
    public static PuzzleGameManager instance = null;

    [SerializeField]
    private int rows = 3, columns = 3;

    [SerializeField]
    private Sprite pauseSprite, playSprite;

    [SerializeField]
    private GameObject gameFinishPanel, menuPanel, menuButton, hintPanel;

    [SerializeField]
    private TextMeshProUGUI moveText, originText, currentText;

    public Sprite picture;


    [HideInInspector]
    public bool playing = true, finish = false;

    [HideInInspector]
    public int[,] map;

    [HideInInspector]
    public Vector3 fixedSize;

    private int moveCount = 0;
    private bool menu = false, hint = false;

    public void SetInitialValue(int rows, int columns, Sprite picture) {
        this.rows = rows;
        this.columns = columns;
        this.picture = picture;
    }

    void Awake() {
        if (instance == null) {
            instance = this;
        }
    }

    void Start() {
        map = GenerateSolvablePuzzle();
        if (picture == null) NumberGameManager.instance.GenerateMap(map);
        else PictureGameManager.instance.GenerateMap(map, picture);
    }

    private int[,] GenerateSolvablePuzzle() {
        int moves = rows*rows*columns*columns;
        
        int[,] puzzle = new int[rows, columns];
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                puzzle[row, col] = row * columns + col + 1;
            }
        }
        puzzle[rows - 1, columns - 1] = 0;

        int emptyX = rows - 1;
        int emptyY = columns - 1;

        int[,] directions = new int[4, 2] { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        System.Random rand = new();

        for (int move = 0; move < moves; move++) {
            List<(int, int)> validMoves = new();

            for (int d = 0; d < 4; d++) {
                int newX = emptyX + directions[d, 0];
                int newY = emptyY + directions[d, 1];

                if (0 <= newX && newX < rows && 0 <= newY && newY < columns) validMoves.Add((newX, newY));
            }

            var chosenMove = validMoves[rand.Next(validMoves.Count)];
            int targetX = chosenMove.Item1;
            int targetY = chosenMove.Item2;

            puzzle[emptyX, emptyY] = puzzle[targetX, targetY];
            puzzle[targetX, targetY] = 0;

            emptyX = targetX;
            emptyY = targetY;
        }

        while (emptyX < rows-1) {
            int targetX = emptyX+1;
            int targetY = emptyY;

            puzzle[emptyX, emptyY] = puzzle[targetX, targetY];
            puzzle[targetX, targetY] = 0;
            
            emptyX = targetX;
            emptyY = targetY;
        }

        while (emptyY < columns-1) {
            int targetX = emptyX;
            int targetY = emptyY+1;

            puzzle[emptyX, emptyY] = puzzle[targetX, targetY];
            puzzle[targetX, targetY] = 0;

            emptyX = targetX;
            emptyY = targetY;
        }

        DrawMap(puzzle, "초기 배치 ", originText);

        return puzzle;
    }

    private bool IsSolvable(int[,] puzzle) {
        List<int> flatPuzzle = new();
        int blank_row = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (puzzle[i, j] == 0) blank_row = rows-i;
                else flatPuzzle.Add(puzzle[i, j]);
            }
        }

        int inversions = 0;
        for (int i = 0; i < flatPuzzle.Count; i++) {
            for (int j = i + 1; j < flatPuzzle.Count; j++) {
                if (flatPuzzle[i] > flatPuzzle[j]) inversions++;
            }
        }

        if (columns % 2 == 1) return inversions % 2 == 0;
        else return (blank_row + inversions) % 2 == 1;
    }

    private void DrawMap(int[,] map, string title, TextMeshProUGUI textUI) {
        StringBuilder s = new StringBuilder();
        s.Append(title+IsSolvable(map)+"\n");
        for (int row = 0; row < rows; row++) {
            StringBuilder tmp = new StringBuilder();
            for (int col = 0; col < columns; col++) {
                tmp.Append(map[row, col]+" ");
            }
            s.Append(tmp+"\n");
        }
        textUI.SetText(s);
    }

    private bool CheckFinish() {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (row == rows-1 && col == columns-1) break;
                if (map[row, col] != row*columns+col+1) return false;
            }
        }
        return true;
    }

    private bool CheckIndex(int row, int col) {
        if (0 <= row && row < rows && 0 <= col && col < columns ) {
            if (map[row, col] == 0) {
                return true;
            }
        }
        return false;
    }

    public string CheckGo(Vector3 originPosition) {
        int originRow = (int) ((fixedSize.y*rows/2-originPosition.y) / fixedSize.y);
        int originCol = (int) ((fixedSize.x*columns/2+originPosition.x) / fixedSize.x);

        if (CheckIndex(originRow-1, originCol)) return "up";
        if (CheckIndex(originRow+1, originCol)) return "down";
        if (CheckIndex(originRow, originCol-1)) return "left";
        if (CheckIndex(originRow, originCol+1)) return "right";

        return "false";
    }

    public void MoveTile(GameObject obj, Vector3 originPosition, Vector3 currentPosition, Vector3 targetPosition, string go) {
        Vector3 direction = targetPosition - currentPosition;
        int originRow = (int) ((fixedSize.y*rows/2-originPosition.y) / fixedSize.y);
        int originCol = (int) ((fixedSize.x*columns/2+originPosition.x) / fixedSize.x);

        float midOriginX = -(fixedSize.x*columns/2-originCol*fixedSize.x-fixedSize.x/2);
        float midOriginY = +(fixedSize.y*rows/2-originRow*fixedSize.y-fixedSize.y/2);

        if (go == "up"){
            float nextY = +(fixedSize.y*rows/2-(originRow-1)*fixedSize.y-fixedSize.y/2);
            if (direction.y > 0) {
                if (targetPosition.y > nextY) obj.transform.position = new Vector3(midOriginX, nextY, obj.transform.position.z);
                else obj.transform.position = new Vector3(midOriginX, targetPosition.y, obj.transform.position.z);
            } else {
                if (targetPosition.y < midOriginY) obj.transform.position = new Vector3(midOriginX, midOriginY, obj.transform.position.z);
                else obj.transform.position = new Vector3(midOriginX, targetPosition.y, obj.transform.position.z);
            }
        } else if (go == "down") {
            float nextY = +(fixedSize.y*rows/2-(originRow+1)*fixedSize.y-fixedSize.y/2);
            if (direction.y < 0) {
                if (targetPosition.y < nextY) obj.transform.position = new Vector3(midOriginX, nextY, obj.transform.position.z);
                else obj.transform.position = new Vector3(midOriginX, targetPosition.y, obj.transform.position.z);
            } else {
                if (targetPosition.y > midOriginY) obj.transform.position = new Vector3(midOriginX, midOriginY, obj.transform.position.z);
                else obj.transform.position = new Vector3(midOriginX, targetPosition.y, obj.transform.position.z);
            }
        } else if (go == "left"){
            float nextX = -(fixedSize.x*columns/2-(originCol-1)*fixedSize.x-fixedSize.x/2);
            if (direction.x < 0) {
                if (targetPosition.x < nextX) obj.transform.position = new Vector3(nextX, midOriginY, obj.transform.position.z);
                else obj.transform.position = new Vector3(targetPosition.x, midOriginY, obj.transform.position.z);
            } else {
                if (targetPosition.x > midOriginX) obj.transform.position = new Vector3(midOriginX, midOriginY, obj.transform.position.z);
                else obj.transform.position = new Vector3(targetPosition.x, midOriginY, obj.transform.position.z);
            }
        } else if (go == "right"){
            float nextX = -(fixedSize.x*columns/2-(originCol+1)*fixedSize.x-fixedSize.x/2);
            if (direction.x > 0) {
                if (targetPosition.x > nextX) obj.transform.position = new Vector3(nextX, midOriginY, obj.transform.position.z);
                else obj.transform.position = new Vector3(targetPosition.x, midOriginY, obj.transform.position.z);
            } else {
                if (targetPosition.x < midOriginX) obj.transform.position = new Vector3(midOriginX, midOriginY, obj.transform.position.z);
                else obj.transform.position = new Vector3(targetPosition.x, midOriginY, obj.transform.position.z);
            }
        }
    }

    public void PlaceTile(GameObject obj, Vector3 originPosition, Vector3 currentPosition) {
        int currentRow = (int) ((fixedSize.y*rows/2-currentPosition.y) / fixedSize.y);
        int currentCol = (int) ((fixedSize.x*columns/2+currentPosition.x) / fixedSize.x);

        int originRow = (int) ((fixedSize.y*rows/2-originPosition.y) / fixedSize.y);
        int originCol = (int) ((fixedSize.x*columns/2+originPosition.x) / fixedSize.x);

        if (currentRow != originRow || currentCol != originCol) {
            float midCurrentX = -(fixedSize.x*columns/2-currentCol*fixedSize.x-fixedSize.x/2);
            float midCurrentY = +(fixedSize.y*rows/2-currentRow*fixedSize.y-fixedSize.y/2);

            map[currentRow, currentCol] = map[originRow, originCol];
            map[originRow, originCol] = 0;

            obj.transform.position = new Vector3(midCurrentX, midCurrentY, obj.transform.position.z);

            moveCount++;
            moveText.SetText(moveCount.ToString());
            if (CheckFinish()) {
                playing = false;
                finish = true;
                menuButton.SetActive(false);
                Invoke("GameFinish", 1f);
            }
        } else obj.transform.position = originPosition;
    }

    private void GameFinish() {
        gameFinishPanel.SetActive(true);
    }

    public void CloseGameFinishPanel() {
        gameFinishPanel.SetActive(false);
        menuButton.SetActive(true);
    }

    public void HintActive() {
        menuPanel.SetActive(false);

        DrawMap(map, "현재 배치 ", currentText);

        hint = !hint;
        hintPanel.SetActive(hint);
        if (!hint) MenuActive();
    }

    public void MenuActive() {
        playing = menu;
        menu = !menu;
        menuPanel.SetActive(menu);

        Image buttonImage = menuButton.GetComponent<Image>();
        if (menu) buttonImage.sprite = playSprite;
        else {
            buttonImage.sprite = pauseSprite;
            if (hint) {
                hint = !hint;
                hintPanel.SetActive(hint);
            }
        }
    }

    public void PlayAgain() {
        SceneManager.sceneLoaded += OnSceneLoaded;
        if (picture == null) SceneManager.LoadScene("NumberSlidingScene");
        else SceneManager.LoadScene("PictureSlidingScene");
    }

    void OnSceneLoaded(Scene scene, LoadSceneMode mode) {
        GameObject gameManager = GameObject.Find("PuzzleGameManager");
        gameManager?.GetComponent<PuzzleGameManager>().SetInitialValue(rows, columns, picture)   ;
        SceneManager.sceneLoaded -= OnSceneLoaded;
    }

    public void GoHome() {
        SceneManager.LoadScene("MainScene");
    }
}