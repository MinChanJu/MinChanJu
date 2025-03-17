using UnityEngine;
using UnityEngine.UIElements;

public class Bird : MonoBehaviour
{
    Rigidbody2D rb;

    [SerializeField]
    private float jumpPower = 3f;

    [SerializeField]
    private float maxY;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        if (GameManager.instance.playing && Input.GetMouseButtonDown(0) && transform.position.y < maxY) {
            rb.linearVelocity = Vector2.up * jumpPower;
        }
    }

    private void OnTriggerEnter2D(Collider2D other) {
        if (other.gameObject.tag == "Pipe") {
            GameManager.instance.gameOver();
            rb.gravityScale = 0;
            rb.linearVelocity = Vector2.zero;
        }
    }
}