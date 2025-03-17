using UnityEngine;

public class PictureGameManager : MonoBehaviour
{
    public static PictureGameManager instance = null;

    [SerializeField]
    private GameObject pictureTile, outerBox;

    private int rows, columns;

    private Vector3 screenSize, fixedSize;

    void Awake() {
        if (instance == null) {
            instance = this;
        }
        screenSize = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, 0));
    }

    public void GenerateMap(int[,] map, Sprite picture) {
        rows = map.GetLength(0);
        columns = map.GetLength(1);

        Texture2D texture = SpriteToTexture(picture);
        Sprite[,] SliceImage = ImageSlicing(texture, rows, columns);

        if (screenSize.x*texture.height/texture.width < screenSize.y) fixedSize = new Vector3(screenSize.x*1.5f / columns, screenSize.x*texture.height*1.5f / (texture.width*rows), 0);
        else fixedSize = new Vector3(screenSize.y*texture.width*1.5f / (texture.height*columns), screenSize.y*1.5f / rows, 0);

        PuzzleGameManager.instance.fixedSize = fixedSize;

        GameObject outerObj = Instantiate(outerBox, transform);

        Renderer renderer = outerObj.GetComponent<Renderer>();
        if (renderer != null) {
            Vector3 currentSize = renderer.bounds.size;
            Vector3 scaleAdjustment = new(fixedSize.x*columns*1.1f / currentSize.x, fixedSize.y*rows*1.1f / currentSize.y, 0);
            outerObj.transform.localScale = Vector3.Scale(outerObj.transform.localScale, scaleAdjustment);
            outerObj.transform.position = new Vector3(0, 0, 0);
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (map[row, col] != 0) {
                    int pos = map[row, col] - 1;
                    GenerateMap(pictureTile, row, col, SliceImage[pos/columns, pos%columns]);
                }
            }
        }
    }

    private void GenerateMap(GameObject obj, int row, int col, Sprite sprite) {
        GameObject generateObj = Instantiate(obj, transform);

        SpriteRenderer spriteRenderer = generateObj.GetComponent<SpriteRenderer>();
        spriteRenderer.sprite = sprite;
        BoxCollider2D boxCollider2D = generateObj.GetComponent<BoxCollider2D>();
        PictureTile pictureTile = generateObj.GetComponent<PictureTile>();
        pictureTile.UpdateBoxCollider(boxCollider2D, spriteRenderer);

        Renderer renderer = generateObj.GetComponent<Renderer>();
        if (renderer != null) {
            Vector3 currentSize = renderer.bounds.size;
            Vector3 scaleAdjustment = new(fixedSize.x / currentSize.x, fixedSize.y / currentSize.y, 0);

            generateObj.transform.localScale = Vector3.Scale(generateObj.transform.localScale, scaleAdjustment);

            float posX = -(fixedSize.x*columns/2-col*fixedSize.x-fixedSize.x/2);
            float posY = +(fixedSize.y*rows/2-row*fixedSize.y-fixedSize.y/2);
            generateObj.transform.position = new Vector3(posX, posY, 0);
        }
    }

    private Texture2D SpriteToTexture(Sprite sprite) {
        Texture2D texture = sprite.texture;

        Rect spriteRect = sprite.textureRect;

        Texture2D croppedTexture = new Texture2D((int)spriteRect.width, (int)spriteRect.height);
        Color[] pixels = texture.GetPixels((int)spriteRect.x, (int)spriteRect.y, (int)spriteRect.width, (int)spriteRect.height);
        croppedTexture.SetPixels(pixels);
        croppedTexture.Apply();

        return croppedTexture;
    }

    private Sprite[,] ImageSlicing(Texture2D texture, int rows, int columns) {
        int width = texture.width / columns;
        int height = texture.height / rows;

        Sprite[,] image = new Sprite[rows, columns];

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                int flippedY = texture.height - (row + 1) * height;

                Rect sliceRect = new(col * width, flippedY, width, height);
                Texture2D slice = new(width, height);

                Color[] pixels = texture.GetPixels((int)sliceRect.x, (int)sliceRect.y, (int)sliceRect.width, (int)sliceRect.height);
                slice.SetPixels(pixels);
                slice.Apply();

                Sprite sprite = Sprite.Create(slice, new Rect(0, 0, slice.width, slice.height), new Vector2(0.5f, 0.5f));

                image[row, col] = sprite;
            }
        }

        return image;
    }
}