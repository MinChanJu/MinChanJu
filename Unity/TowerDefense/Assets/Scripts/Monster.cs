using System;
using UnityEngine;

public class Monster : MonoBehaviour
{
    [SerializeField]
    public int hp = 10, damage = 1, reward = 1;

    [SerializeField]
    private float moveSpeed = 0f;

    private GameObject wayPoint;

    private Vector3 fixedSize;

    private Animator animator;
    
    private bool change = true, back = false, front = false, left = true, right = false;

    void Start() {
        moveSpeed = GameManager.instance.monsterSpeed / 10;

        fixedSize = GameManager.instance.fixedSize;

        animator = GetComponent<Animator>();

        Renderer renderer = GetComponent<Renderer>();
        if (renderer != null) {
            Vector3 currentSize = renderer.bounds.size;
            Vector3 scaleAdjustment;
            if (fixedSize.x < fixedSize.y) scaleAdjustment = new Vector3(fixedSize.x / currentSize.x, fixedSize.x / currentSize.x, 1);
            else scaleAdjustment = new Vector3(fixedSize.y / currentSize.y, fixedSize.y / currentSize.y, 1);

            transform.localScale = Vector3.Scale(transform.localScale, scaleAdjustment);
        }
    }

    void Update() {
        if (GameManager.instance.playing && wayPoint) {
            Vector3 targetPosition = new(wayPoint.transform.position.x, wayPoint.transform.position.y, transform.position.z);
            Vector3 direction = (targetPosition - transform.position).normalized;

            if (change) {
                if (Math.Abs(direction.x) > Math.Abs(direction.y)) {
                    if (direction.x > 0) {
                        back = false; front = false; left = false; right = true;
                    } else {
                        back = false; front = false; left = true; right = false;
                    }
                } else {
                    if (direction.y > 0) {
                        back = true; front = false; left = false; right = false;
                    } else {
                        back = false; front = true; left = false; right = false;
                    }
                }

                SetAnimator();
                change = false;
            }
            
            transform.position += direction * moveSpeed * Time.deltaTime;

            if (Vector3.Distance(transform.position, targetPosition) < 0.01f) {
                transform.position = targetPosition;

                WayPoint nextWay = wayPoint.GetComponent<WayPoint>();
                wayPoint = nextWay.GetNextWayPoint();
                change = true;

                if (wayPoint == null) {
                    GameManager.instance.monsters.Remove(gameObject);
                    Destroy(gameObject);
                }
            }
        }
    }

    public void SetWayPoint(GameObject wayPoint) {
        this.wayPoint = wayPoint;
    }

    private void SetAnimator() {
        animator.SetBool("Back", back);
        animator.SetBool("Front", front);
        animator.SetBool("Left", left);
        animator.SetBool("Right", right);
    }
}
