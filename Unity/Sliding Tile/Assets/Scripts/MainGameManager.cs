using System.IO;
using TMPro;
// using UnityEditor;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MainGameManager : MonoBehaviour
{
    [SerializeField]
    private GameObject settingPanel, pictureChoosePanel, notificationPanel;

    [SerializeField]
    private TextMeshProUGUI notificationText;

    [SerializeField]
    private TMP_InputField rowInput, columnInput;

    private Sprite picture;

    private int rows, columns;

    private bool setting = false, pictureChoose = false;

    void Start() {
        InitValue();
    }

    public void LoadImagePlatform() {
        #if UNITY_ANDROID
            LoadImageAndroid();
        // #elif UNITY_EDITOR
        //     LoadImageEditor();
        #endif
    }

    // private void LoadImageEditor() {
    //     string path = EditorUtility.OpenFilePanel("Select an Image", "", "png,jpg");
    //     if (!string.IsNullOrEmpty(path)) LoadTexture(path);
    // }

    private void LoadImageAndroid() {
        NativeGallery.Permission permission = NativeGallery.GetImageFromGallery((path) => {
            if (path != null) LoadTexture(path);
        }, "Select an Image", "image/*");
    }

    private void LoadTexture(string filePath) {
        byte[] fileData = File.ReadAllBytes(filePath);
        Texture2D texture = new(2, 2);
        texture.LoadImage(fileData);
        picture = TextureToSprite(texture);
    }

    private Sprite TextureToSprite(Texture2D texture) {
        return Sprite.Create(
            texture,
            new Rect(0, 0, texture.width, texture.height),
            new Vector2(0.5f, 0.5f)
        );
    }

    public void InitValue() {
        rows = 5;
        columns = 5;
        rowInput.text = rows.ToString();
        columnInput.text = columns.ToString();
        picture = null;
    }

    public void SettingPanelActive() {
        setting = !setting;
        settingPanel.SetActive(setting);
    }

    public void PictureChoosePanelActive() {
        pictureChoose = !pictureChoose;
        pictureChoosePanel.SetActive(pictureChoose);
    }

    public void ChangeRow() {
        string s = rowInput.text;
        rows = int.Parse(s);
    }

    public void ChangeColumn() {
        string s = columnInput.text;
        columns = int.Parse(s);
    }

    public void ChangePicture(Sprite picture) {
        this.picture = picture;
    }

    public void GoPuzzle() {
        if (3 <= rows && rows <= 15 && 3 <= columns && columns <= 15) {
            SceneManager.sceneLoaded += OnSceneLoaded;
            if (picture == null) SceneManager.LoadScene("NumberSlidingScene");
            else SceneManager.LoadScene("PictureSlidingScene");
        } else ShowNotification("가로 세로를 3 이상 15 이하로 설정해주세요");
    }

    void OnSceneLoaded(Scene scene, LoadSceneMode mode) {
        GameObject gameManager = GameObject.Find("PuzzleGameManager");
        gameManager?.GetComponent<PuzzleGameManager>().SetInitialValue(rows, columns, picture);
        SceneManager.sceneLoaded -= OnSceneLoaded;
    }

    private void ShowNotification(string message, float duration = 2f) {
        notificationText.text = message;
        notificationPanel.SetActive(true);
        Invoke("HideNotification", duration);
    }

    private void HideNotification() {
        notificationPanel.SetActive(false);
    }
}