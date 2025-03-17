using UnityEngine;

public class Ground : MonoBehaviour
{
    private float moveSpeed;
    
    // Update is called once per frame
    void Update()
    {
        if (GameManager.instance.playing) {
            transform.position += Vector3.left * moveSpeed * Time.deltaTime;
            if (transform.position.x < -5) {
                transform.position += new Vector3(10, 0, 0);
            }
        }
    }

    public void setSpeed(float moveSpeed) {
        this.moveSpeed = moveSpeed;
    }
}
