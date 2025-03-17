using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static GameManager instance = null;

    [HideInInspector]
    public bool playing = true;

    [HideInInspector]
    public Vector3 screenSize;

    [SerializeField]
    private float moveSpeed;

    [SerializeField]
    private TextMeshProUGUI pipeText;

    [SerializeField]
    private GameObject gameOverPanel;

    private int pipe = 0;

    void Awake() {
        if (instance == null) {
            instance = this;
        }
        GameObject pipeSpawnerObject = GameObject.Find("PipeSpawner");
        GameObject groundObject = GameObject.Find("Ground");
        PipeSpawner pipeSpawner = pipeSpawnerObject.GetComponent<PipeSpawner>();
        Ground ground = groundObject.GetComponent<Ground>();
        pipeSpawner.setSpeed(moveSpeed);
        ground.setSpeed(moveSpeed);
        screenSize = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, 0));
    }

    public void increasePipe() {
        pipe++;
        pipeText.SetText(pipe.ToString());
    }

    public void gameOver() {
        playing = false;
        gameOverPanel.SetActive(true);
    }

    public void PlayAgain() {
        SceneManager.LoadScene("SampleScene");
    }
}
