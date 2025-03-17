using System.Collections;
using UnityEngine;

public class MonsterSpawner : MonoBehaviour
{

    [SerializeField]
    private float startInterval = 3f, spawnInterval = 3f;

    [SerializeField]
    private GameObject initialWayPoint;


    private int index = 0, cnt = 0, monsterUpgradeInterval;

    private GameObject[] monsters;

    void Start() {
        monsters = Resources.LoadAll<GameObject>("Monsters");

        startInterval = GameManager.instance.monsterStartInterval;
        spawnInterval = GameManager.instance.monsterSpawnInterval;

        monsterUpgradeInterval = GameManager.instance.monsterUpgradeInterval;

        StartMonsterRoutine();
    }

    public void StartMonsterRoutine() {
        StartCoroutine("MonsterRoutine");
    }

    public void StopMonsterRoutine() {
        StopCoroutine("MonsterRoutine");
    }

    IEnumerator MonsterRoutine() {
        yield return new WaitForSeconds(startInterval);

        while (true) {
            GameObject monsterObj = Instantiate(monsters[index], transform.position, Quaternion.identity);
            monsterObj.transform.SetParent(transform);
            GameManager.instance.monsters.Add(monsterObj);

            Monster monster = monsterObj.GetComponent<Monster>();
            monster.SetWayPoint(initialWayPoint);

            cnt++;
            if (cnt%monsterUpgradeInterval == 0) {
                index++;
                cnt = 0;
            }
            if (index >= monsters.Length) index = monsters.Length - 1;

            yield return new WaitForSeconds(spawnInterval);
        }
    }

    public void SetInitialWayPoint(GameObject wayPoint) {
        initialWayPoint = wayPoint;
    }

    public void SetSpawnInterval(float spawnInterval) {
        this.spawnInterval = spawnInterval;
    }
}
