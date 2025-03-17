using TMPro;
using UnityEngine;

public class NumberGameManager : MonoBehaviour
{
    public static NumberGameManager instance = null;

    [SerializeField]
    private GameObject numberTile, outerBox;

    private int rows, columns;

    private Vector3 screenSize, fixedSize;

    void Awake() {
        if (instance == null) {
            instance = this;
        }
        screenSize = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, 0));
    }

    public void GenerateMap(int[,] map) {
        rows = map.GetLength(0);
        columns = map.GetLength(1);

        if (screenSize.x*rows*1.5f < screenSize.y*columns) fixedSize = new Vector3(screenSize.x*1.5f / columns, screenSize.x*1.5f / columns, 0);
        else fixedSize = new Vector3(screenSize.y / rows, screenSize.y / rows, 0);

        PuzzleGameManager.instance.fixedSize = fixedSize;

        GameObject outerObj = Instantiate(outerBox, transform);

        Renderer renderer = outerObj.GetComponent<Renderer>();
        if (renderer != null) {
            Vector3 currentSize = renderer.bounds.size;
            Vector3 scaleAdjustment = new(fixedSize.x*columns*1.1f / currentSize.x, fixedSize.y*rows*1.1f / currentSize.y, 0);
            outerObj.transform.localScale = Vector3.Scale(outerObj.transform.localScale, scaleAdjustment);
            outerObj.transform.position = new Vector3(0, 0, 0);
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (map[row, col] != 0) GenerateMap(numberTile, row, col, map[row, col]);
            }
        }
    }

    private void GenerateMap(GameObject obj, int row, int col, int num) {
        GameObject generateObj = Instantiate(obj, transform);

        TextMeshPro textMeshPro = generateObj.GetComponentInChildren<TextMeshPro>();
        textMeshPro.text = num.ToString();

        Renderer renderer = generateObj.GetComponent<Renderer>();
        if (renderer != null) {
            Vector3 currentSize = renderer.bounds.size;
            Vector3 scaleAdjustment = new(fixedSize.x / currentSize.x, fixedSize.y / currentSize.y, 0);

            generateObj.transform.localScale = Vector3.Scale(generateObj.transform.localScale, scaleAdjustment);

            float posX = -(fixedSize.x*columns/2-col*fixedSize.x-fixedSize.x/2);
            float posY = +(fixedSize.y*rows/2-row*fixedSize.y-fixedSize.y/2);
            generateObj.transform.position = new Vector3(posX, posY, 0);
        }
    }
}
