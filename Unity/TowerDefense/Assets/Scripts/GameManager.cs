using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public static GameManager instance = null;

    [SerializeField]
    private GameObject menuButton, menuPanel, developerPanel, gameOverPanel;

    [SerializeField]
    private Sprite pauseSprite, playSprite;

    [SerializeField]
    private TextMeshProUGUI timeText, coinText;
    
    [SerializeField]
    private TMP_InputField monstertIntervalChangeText, monsterSpeedChangeText, coinChangeText;

    [SerializeField]
    private int mapIndex = -1;

    public int coin = 10, monsterUpgradeInterval = 30;

    public float monsterSpeed = 1f, monsterStartInterval = 3f, monsterSpawnInterval = 3f, mapSize = 0.8f;

    [HideInInspector]
    public bool playing = true;

    [HideInInspector]
    public int[,] map;

    [HideInInspector]
    public Vector3 screenSize, fixedSize;

    [HideInInspector]
    public List<GameObject> monsters = new() { };

    private float startTime, totalTime, lastTime, elapsedTime;

    private bool menu = false;

    private void Awake() {
        if (instance == null) {
            instance = this;
        }

        TextAsset[] mapFiles = Resources.LoadAll<TextAsset>("Maps");

        TextAsset selectedMapFile = mapFiles[Random.Range(0, mapFiles.Length)];

        if (0 <= mapIndex) {
            if (mapIndex >= mapFiles.Length) mapIndex = mapFiles.Length - 1;
            selectedMapFile = mapFiles[mapIndex];
        }

        map = ParseMapData(selectedMapFile.text);
        screenSize = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, 0));
        fixedSize = new Vector3(screenSize.x*2/map.GetLength(1), screenSize.y*2*mapSize/map.GetLength(0), 0);

        monstertIntervalChangeText.text = monsterSpawnInterval.ToString();
        monsterSpeedChangeText.text = monsterSpeed.ToString();
        coinChangeText.text = coin.ToString();
        coinText.SetText(coin.ToString());

        monsters = new List<GameObject>();
    }

    void Start() {
        startTime = Time.realtimeSinceStartup;
    }

    void Update() {
        if (playing) {
            lastTime = Time.realtimeSinceStartup;
            elapsedTime = lastTime - startTime + totalTime;

            timeText.SetText(elapsedTime.ToString("F2") + " 초");
        }
    }

    private int[,] ParseMapData(string mapData) {
        string[] lines = mapData.Split('\n');
        int rows = lines.Length;
        int cols = lines[0].Split(',').Length;

        int[,] mapArray = new int[rows, cols];

        for (int i = 0; i < rows; i++) {
            string[] values = lines[i].Trim().Split(',');
            for (int j = 0; j < cols; j++) {
                mapArray[i, j] = int.Parse(values[j]);
            }
        }

        return mapArray;
    }

    private bool CheckFloor(int i, int j) {
        if (0 <= i && i < map.GetLength(0)) {
            if (0 <= j && j < map.GetLength(1)) {
                if (map[i, j] == 0) return true;
            }
        }
        return false;
    }

    public void PlaceDefenser(GameObject defenser, Vector3 position) {
        Defenser defen = defenser.GetComponent<Defenser>();
        if (coin < defen.cost) return;

        int currentI = (int) ((screenSize.y - position.y) / fixedSize.y);
        int currentJ = (int) ((screenSize.x + position.x) / fixedSize.x);

        if (CheckFloor(currentI, currentJ)) {
            GameObject defenserObj = Instantiate(defenser);
            coin -= defen.cost;
            coinText.SetText(coin.ToString());
            coinChangeText.text = coin.ToString();

            Renderer renderer = defenserObj.GetComponent<Renderer>();
            if (renderer != null) {
                Vector3 currentSize = renderer.bounds.size;

                Vector3 scaleAdjustment;
                if (fixedSize.x < fixedSize.y) scaleAdjustment = new Vector3(fixedSize.x / currentSize.x, fixedSize.x / currentSize.x, fixedSize.z / currentSize.z);
                else scaleAdjustment = new Vector3(fixedSize.y / currentSize.y, fixedSize.y / currentSize.y, fixedSize.z / currentSize.z);
                
                defenserObj.transform.localScale = Vector3.Scale(defenserObj.transform.localScale, scaleAdjustment);

                float midX = -(screenSize.x-currentJ*fixedSize.x-fixedSize.x/2);
                float midY = +(screenSize.y-currentI*fixedSize.y-fixedSize.y/2);
                defenserObj.transform.position = new Vector3(midX, midY, 0);
            }
            map[currentI, currentJ] = 3;
        }
    }

    public void GameFinish() {
        playing = false;
        MonsterSpawner monsterSpawner = FindAnyObjectByType<MonsterSpawner>();
        if (monsterSpawner != null) {
            monsterSpawner.StopMonsterRoutine();
        }

        Defenser[] allDefensers = FindObjectsByType<Defenser>(FindObjectsSortMode.None);

        foreach (Defenser defenser in allDefensers) {
            defenser.StopDefenserRoutine();
        }

        gameOverPanel.SetActive(true);
        menuButton.SetActive(false);
    }

    public void IncreaseCoin(int reward) {
        coin += reward;
        coinText.SetText(coin.ToString());
        coinChangeText.text = coin.ToString();
    }

    public void MenuActive() {
        totalTime += lastTime-startTime;
        startTime = Time.realtimeSinceStartup;

        playing = menu;
        menu = !menu;
        menuPanel.SetActive(menu);

        Image buttonImage = menuButton.GetComponent<Image>();
        if (menu) buttonImage.sprite = playSprite;
        else {
            buttonImage.sprite = pauseSprite;
            developerPanel.SetActive(menu);
        }

        MonsterSpawner monsterSpawner = FindAnyObjectByType<MonsterSpawner>();
        if (monsterSpawner != null) {
            if (playing) monsterSpawner.StartMonsterRoutine();
            else monsterSpawner.StopMonsterRoutine();
        }

        Defenser[] allDefensers = FindObjectsByType<Defenser>(FindObjectsSortMode.None);

        foreach (Defenser defenser in allDefensers) {
            if (playing) defenser.StartDefenserRoutine();
            else defenser.StopDefenserRoutine();
        }
    }

    public void DeveloperActive() {
        menu = !menu;
        developerPanel.SetActive(!menu);
        menuPanel.SetActive(menu);
        menuButton.SetActive(menu);
    }

    public void ChangeMonsterInterval() {
        string s = monstertIntervalChangeText.text;
        MonsterSpawner monsterSpawner = FindAnyObjectByType<MonsterSpawner>();
        monsterSpawner.SetSpawnInterval(float.Parse(s));
    }

    public void ChangeMonsterSpeed() {
        string s = monsterSpeedChangeText.text;
        monsterSpeed = float.Parse(s);
    }

    public void ChangeCoin() {
        string s = coinChangeText.text;
        coin = int.Parse(s);
        coinText.SetText(coin.ToString());
    }

    public void PlayAgain() {
        SceneManager.LoadScene("DefenseScene");
    }

    public void GoHome() {
        SceneManager.LoadScene("MainScene");
    }
}
