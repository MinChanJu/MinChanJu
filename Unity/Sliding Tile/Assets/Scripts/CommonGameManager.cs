using UnityEngine;
using UnityEngine.UI;

public class CommonGameManager : MonoBehaviour
{
    public static CommonGameManager Instance { get; private set; }

    [SerializeField]
    private Sprite playSprite, pauseSprite;

    [SerializeField]
    private Button musicButton;

    [SerializeField]
    private AudioSource audioSource;

    private Image buttonImage;

    void Awake() {
        if (Instance == null) {
            Instance = this;
            DontDestroyOnLoad(gameObject);
            
            buttonImage = musicButton.GetComponent<Image>();

            bool music = PlayerPrefs.GetInt("IsMusicPlaying", 1) == 1;
            if (music) {
                audioSource.Play();
                buttonImage.sprite = playSprite;
            } else {
                audioSource.Pause();
                buttonImage.sprite = pauseSprite;
            }
        } else {
            Destroy(gameObject);
        }
    }

    void Start()
    {
        musicButton.onClick.RemoveAllListeners();
        musicButton.onClick.AddListener(MusicActive);
    }

    private void MusicActive() {
        if (audioSource.isPlaying) {
            audioSource.Pause();
            buttonImage.sprite = pauseSprite;
            PlayerPrefs.SetInt("IsMusicPlaying", 0);
        } else {
            audioSource.Play();
            buttonImage.sprite = playSprite;
            PlayerPrefs.SetInt("IsMusicPlaying", 1);
        }
        PlayerPrefs.Save();
    }
}
