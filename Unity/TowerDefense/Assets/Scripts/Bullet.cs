using System;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    [SerializeField]
    private float moveSpeed = 0f;

    [SerializeField]
    private int damage = 1;

    private Vector3 screenSize, direction = Vector3.zero;

    private GameObject monster;

    void Start() {
        Vector3 fixedSize = GameManager.instance.fixedSize;

        Renderer renderer = GetComponent<Renderer>();
        if (renderer != null) {
            Vector3 currentSize = renderer.bounds.size;
            Vector3 scaleAdjustment;
            if (fixedSize.x < fixedSize.y) scaleAdjustment = new Vector3(fixedSize.x / 2 / currentSize.x, fixedSize.x / 2 / currentSize.x, 1);
            else scaleAdjustment = new Vector3(fixedSize.y / 2 / currentSize.y, fixedSize.y / 2 / currentSize.y, 1);
            transform.localScale = Vector3.Scale(transform.localScale, scaleAdjustment);
        }

        screenSize = GameManager.instance.screenSize;

        if (GameManager.instance.monsters.Count != 0) {
            double min = -1;
            foreach (GameObject monsterObj in GameManager.instance.monsters) {
                double distance = CheckDistance(monsterObj.transform.position, transform.position);
                if (min == -1 || min > distance) {
                    monster = monsterObj;
                    min = distance;
                }
            }
            direction = (monster.transform.position - transform.position).normalized;
        }
    }

    void Update() {
        if (transform.position.x <= screenSize.x || screenSize.x <= transform.position.x) {
            if (transform.position.y <= -screenSize.y || screenSize.y <= transform.position.y) {
                Destroy(gameObject);
            }
        }
        
        if (GameManager.instance.playing) {
            if (direction == Vector3.zero) {
                if (GameManager.instance.monsters.Count != 0) {
                    GameObject monsterObj = GameManager.instance.monsters[0];
                    direction = (monsterObj.transform.position - transform.position).normalized;
                }
            }

            transform.position += direction * moveSpeed * Time.deltaTime;
        }
    }

    private double CheckDistance(Vector3 pos1, Vector3 pos2) {
        return Math.Sqrt((pos1.x-pos2.x)*(pos1.x-pos2.x) + (pos1.y-pos2.y)*(pos1.y-pos2.y));
    }

    private void OnTriggerEnter2D(Collider2D other) {
        if (other.gameObject.tag == "Monster") {
            Monster monster = other.gameObject.GetComponent<Monster>();
            monster.hp -= damage;

            if (monster.hp <= 0) {
                GameManager.instance.IncreaseCoin(monster.reward);
                GameManager.instance.monsters.Remove(other.gameObject);
                Destroy(other.gameObject);
            }
            Destroy(gameObject);
        }
    }
}
