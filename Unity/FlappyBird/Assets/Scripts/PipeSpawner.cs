using System.Collections;
using UnityEngine;

public class PipeSpawner : MonoBehaviour
{
    [SerializeField]
    private GameObject pipe;

    [SerializeField]
    private float pipeGap = 7f;

    [SerializeField]
    private float spawnInterval = 1.5f;

    private float pipeSpeed;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        transform.position = Vector3.right * GameManager.instance.screenSize.x * 1.5f;
        Debug.Log("position change");
        startPipeRoutine();
    }

    void startPipeRoutine() {
        StartCoroutine("spawnPipe");
    }

    IEnumerator spawnPipe() {
        yield return new WaitForSeconds(1f);

        while (GameManager.instance.playing) {
            float spawnY = Random.Range(-4f, -1f);
            Vector3 spawnUpPos = new Vector3(transform.position.x, spawnY, 0);
            Vector3 spawnDownPos = new Vector3(transform.position.x, spawnY+pipeGap, 0);

            GameObject upPipeObj = Instantiate(pipe, spawnUpPos, Quaternion.identity);
            GameObject downPipeObj = Instantiate(pipe, spawnDownPos, Quaternion.identity);
            downPipeObj.transform.Rotate(0, 0, 180f);

            Pipe upPipe = upPipeObj.GetComponent<Pipe>();
            Pipe downPipe = downPipeObj.GetComponent<Pipe>();

            upPipe.setSpeed(pipeSpeed);
            downPipe.setSpeed(pipeSpeed);

            yield return new WaitForSeconds(spawnInterval);
        }
    }

    public void setSpeed(float pipeSpeed) {
        this.pipeSpeed = pipeSpeed;
    }
}
