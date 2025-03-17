using System.Collections;
using UnityEngine;

public class Defenser : MonoBehaviour
{
    public int cost = 1;

    [SerializeField]
    private GameObject bullet;

    [SerializeField]
    private float bulletInterval = 3f;

    private Vector3 screenSize;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start() {
        StartDefenserRoutine();
        screenSize = GameManager.instance.screenSize;
    }

    public void StartDefenserRoutine() {
        StartCoroutine("DefenserRoutine");
    }

    public void StopDefenserRoutine() {
        StopCoroutine("DefenserRoutine");
    }

    IEnumerator DefenserRoutine() {
        yield return new WaitForSeconds(0.5f);

        while (true) {
            if (GameManager.instance.monsters.Count != 0) {
                GameObject monsterObj = GameManager.instance.monsters[0];
                Vector3 monsterPosition = monsterObj.transform.position;

                if (-screenSize.x <= monsterPosition.x && monsterPosition.x <= screenSize.x) {
                    if (-screenSize.y <= monsterPosition.y && monsterPosition.y <= screenSize.y) {
                        GameObject bulletObj = Instantiate(bullet, transform.position, Quaternion.identity);
                        bulletObj.transform.SetParent(transform);
                        yield return new WaitForSeconds(bulletInterval);
                    }
                }
            }

            yield return new WaitForSeconds(0f);
        }
    }
}
