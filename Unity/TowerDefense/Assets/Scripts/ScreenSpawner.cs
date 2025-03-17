using Unity.Collections;
using Unity.VisualScripting;
using UnityEngine;

public class ScreenSpawner : MonoBehaviour
{
    private int[,] map, menu;

    private Vector3 screenSize, menuSize, fixedSize, menuFixedSize;

    private GameObject grassTile, groundTile, towerTile, menuTile, wayPoint, defenserSpawner, monsterSpawner;

    private GameObject[] defensers;

    private MonsterSpawner monsterSpawnerCla;


    void Awake() {
        grassTile = Resources.Load<GameObject>("Tile/GrassTile");
        groundTile = Resources.Load<GameObject>("Tile/GroundTile");
        menuTile = Resources.Load<GameObject>("Tile/MenuTile");

        towerTile = Resources.Load<GameObject>("Tile/Tower");
        wayPoint = Resources.Load<GameObject>("Tile/WayPoint");

        defenserSpawner = Resources.Load<GameObject>("Tile/DefenserSpawner");
        monsterSpawner = Resources.Load<GameObject>("Tile/MonsterSpawner");

        defensers = Resources.LoadAll<GameObject>("Defensers");
    }

    void Start() {
        map = GameManager.instance.map;
        screenSize = GameManager.instance.screenSize;
        fixedSize = GameManager.instance.fixedSize;

        menuSize = screenSize;
        menuSize.y -= fixedSize.y*map.GetLength(0)/2;

        menu = new int[3, defensers.Length*2+1];
        for (int i = 0; i < defensers.Length; i++) {
            menu[1, 2*i+1] = i+1;
        }

        menuFixedSize = new Vector3(menuSize.x*2/menu.GetLength(1), menuSize.y*2/menu.GetLength(0), 0);

        GenerateMap();
        GenerateMenu(menu);
    }

    private void GenerateMap() {
        int moni = 0, monj = 0;

        Transform grassTrans = transform.Find("Grass");
        Transform groundTrans = transform.Find("Ground");
        Transform wayPointTrans = transform.Find("WayPoint");

        for (int i = 0; i < map.GetLength(0); i++) {
            for (int j = 0; j < map.GetLength(1); j++) {
                if (map[i, j] == 0) GenerateMap(grassTile, i, j, grassTrans);
                else GenerateMap(groundTile, i, j, groundTrans);
                
                if (map[i, j] == 2) GenerateMap(towerTile, i, j, transform);
                else if (map[i, j] == 3) {
                    GameObject monsterSpawnerObj = GenerateMap(monsterSpawner, i, j, transform);
                    monsterSpawnerCla = monsterSpawnerObj.GetComponent<MonsterSpawner>();
                    moni = i;
                    monj = j;
                }
            }
        }

        string go = "";
        if (moni+1 < map.GetLength(0) && map[moni+1, monj] != 0) go = "down";
        if (monj+1 < map.GetLength(1) && map[moni, monj+1] != 0) go = "right";
        if (moni > 0 && map[moni-1, monj] != 0) go = "up";
        if (monj > 0 && map[moni, monj-1] != 0) go = "left";
        WayPoint lastWayPoint = null;

        while (true) {
            bool change = true;
            if (moni+1 < map.GetLength(0) && map[moni+1, monj] != 0 && change) {
                if (go == "down") {moni++; continue;}
                else if (go != "up") {go = "down"; change = false;}
            }
            if (monj+1 < map.GetLength(1) && map[moni, monj+1] != 0 && change) {
                if (go == "right") {monj++; continue;}
                else if (go != "left") {go = "right"; change = false;}
            }
            if (moni > 0 && map[moni-1, monj] != 0 && change) {
                if (go == "up") {moni--; continue;}
                else if (go != "down") {go = "up"; change = false;}
            }
            if (monj > 0 && map[moni, monj-1] != 0 && change) {
                if (go == "left") {monj--; continue;}
                else if (go != "right") {go = "left";}
            }

            GameObject wayPointObj = GenerateMap(wayPoint, moni, monj, wayPointTrans);
            if (lastWayPoint) lastWayPoint.SetNextWayPoint(wayPointObj);
            else monsterSpawnerCla.SetInitialWayPoint(wayPointObj);
            lastWayPoint = wayPointObj.GetComponent<WayPoint>();

            if (map[moni, monj] == 2) break;

            if (go == "down") moni++;
            if (go == "right") monj++;
            if (go == "up") moni--;
            if (go == "left") monj--;
        }
    }

    private GameObject GenerateMap(GameObject obj, int i, int j, Transform targetChild) {
        GameObject generateObj = Instantiate(obj, targetChild);

        Renderer renderer = generateObj.GetComponent<Renderer>();
        if (renderer != null) {
            Vector3 currentSize = renderer.bounds.size;
            Vector3 scaleAdjustment = new Vector3(fixedSize.x / currentSize.x, fixedSize.y / currentSize.y, fixedSize.z / currentSize.z);

            generateObj.transform.localScale = Vector3.Scale(generateObj.transform.localScale, scaleAdjustment);

            float posX = -(screenSize.x-j*fixedSize.x-fixedSize.x/2);
            float posY = +(screenSize.y-i*fixedSize.y-fixedSize.y/2);
            generateObj.transform.position = new Vector3(posX, posY, 0);
        }

        return generateObj;
    }

    private void GenerateMenu(int[,] menuArray) {

        Transform menuTrans = transform.Find("Menu");

        for (int i = 0; i < menuArray.GetLength(0); i++) {
            for (int j = 0; j < menuArray.GetLength(1); j++) {
                GenerateMenu(menuTile, i, j, menuTrans);
                if (menuArray[i, j] != 0) GenerateMenu(defenserSpawner, defensers[j/2], i, j, menuTrans);
            }
        }
    }

    private void GenerateMenu(GameObject obj, int i, int j, Transform targetChild) {
        GameObject generateObj = Instantiate(obj, targetChild);

        Renderer renderer = generateObj.GetComponent<Renderer>();
        if (renderer != null) {
            Vector3 currentSize = renderer.bounds.size;
            Vector3 scaleAdjustment = new Vector3(menuFixedSize.x / currentSize.x, menuFixedSize.y / currentSize.y, menuFixedSize.z / currentSize.z);

            generateObj.transform.localScale = Vector3.Scale(generateObj.transform.localScale, scaleAdjustment);

            float posX = -(screenSize.x - j*menuFixedSize.x - menuFixedSize.x/2);
            float posY = -(screenSize.y + i*menuFixedSize.y + menuFixedSize.y/2) + menuSize.y*2;
            generateObj.transform.position = new Vector3(posX, posY, 0);
        }
    }

    private void GenerateMenu(GameObject obj, GameObject defenser, int i, int j, Transform targetChild) {
        GameObject generateObj = Instantiate(obj, targetChild);

        DefenserSpawner defenserSpawner = generateObj.GetComponent<DefenserSpawner>();
        defenserSpawner.SetDefenser(defenser);

        SpriteRenderer spriteRenderer = generateObj.GetComponent<SpriteRenderer>();
        spriteRenderer.sprite = defenser.GetComponent<SpriteRenderer>().sprite;

        Renderer renderer = generateObj.GetComponent<Renderer>();
        if (renderer != null) {
            Vector3 currentSize = renderer.bounds.size;
            Vector3 scaleAdjustment;
            if (menuFixedSize.x < menuFixedSize.y) scaleAdjustment = new Vector3(menuFixedSize.x / currentSize.x, menuFixedSize.x / currentSize.x, menuFixedSize.z / currentSize.z);
            else scaleAdjustment = new Vector3(menuFixedSize.y / currentSize.y, menuFixedSize.y / currentSize.y, menuFixedSize.z / currentSize.z);

            generateObj.transform.localScale = Vector3.Scale(generateObj.transform.localScale, scaleAdjustment);

            float posX = -(screenSize.x - j*menuFixedSize.x - menuFixedSize.x/2);
            float posY = -(screenSize.y + i*menuFixedSize.y + menuFixedSize.y/2) + menuSize.y*2;
            generateObj.transform.position = new Vector3(posX, posY, 0);
        }
    }
}
