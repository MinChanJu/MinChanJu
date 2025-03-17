using UnityEngine;

public class Pipe : MonoBehaviour
{
    private float moveSpeed;

    private bool increase = true;


    // Update is called once per frame
    void Update()
    {
        if (GameManager.instance.playing) {
            transform.position -= Vector3.right * moveSpeed * Time.deltaTime;
            if (transform.position.x <= -GameManager.instance.screenSize.x*1.5) {
                Destroy(gameObject);
            }
            if (increase && transform.position.x <= -2 && transform.position.y <= 0f) {
                increase = false;
                GameManager.instance.increasePipe();
            }
        }
    }

    public void setSpeed(float moveSpeed) {
        this.moveSpeed = moveSpeed;
    }
}
