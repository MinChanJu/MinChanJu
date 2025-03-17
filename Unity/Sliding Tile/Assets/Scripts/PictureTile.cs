using UnityEngine;

public class PictureTile : MonoBehaviour
{
    private bool isDragging = false;

    private Vector3 originalPosition;

    private string go;

    void Update() {
        if (isDragging && PuzzleGameManager.instance.playing && !PuzzleGameManager.instance.finish) {
            Vector3 mousenPosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            PuzzleGameManager.instance.MoveTile(gameObject, originalPosition, transform.position, mousenPosition, go);
        }
    }

    void OnMouseDown()
    {
        isDragging = true;
        originalPosition = transform.position;
        go = PuzzleGameManager.instance.CheckGo(originalPosition);
    }

    void OnMouseUp() {
        isDragging = false;
        PuzzleGameManager.instance.PlaceTile(gameObject, originalPosition, transform.position);
    }

    public void UpdateBoxCollider(BoxCollider2D boxCollider, SpriteRenderer spriteRenderer) {
        if (boxCollider != null && spriteRenderer.sprite != null) {
            boxCollider.size = spriteRenderer.sprite.bounds.size;
        }
    }
}
