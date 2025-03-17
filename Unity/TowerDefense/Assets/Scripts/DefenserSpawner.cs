using UnityEngine;
using UnityEngine.InputSystem;

public class DefenserSpawner : MonoBehaviour
{
    private GameObject defenser;

    private bool isDragging = false;
    private Vector3 originalPosition, fixedSize;

    void Start() {
        originalPosition = transform.position;
        fixedSize = GameManager.instance.fixedSize;
    }

    void Update() {
        if (GetTouchOrMousePosition() != Vector2.zero) {
            Vector2 touchPosition = GetTouchOrMousePosition();
            Vector3 worldPosition = Camera.main.ScreenToWorldPoint(new Vector3(touchPosition.x, touchPosition.y, 0));

            if (!isDragging) {
                if (originalPosition.x - fixedSize.x/2 <= worldPosition.x && worldPosition.x <= originalPosition.x + fixedSize.x/2) {
                    if (originalPosition.y - fixedSize.y/2 <= worldPosition.y && worldPosition.y <= originalPosition.y + fixedSize.y/2) {
                        isDragging = true;
                    }
                }
            } else {
                transform.position = new Vector3(worldPosition.x, worldPosition.y, transform.position.z);
            }
        } else if (isDragging) {
            isDragging = false;
            Vector3 dropPosition = new Vector3(transform.position.x, transform.position.y,0);

            GameManager.instance.PlaceDefenser(defenser, dropPosition);

            transform.position = originalPosition;
        }
    }

    private Vector2 GetTouchOrMousePosition() {
        if (Touchscreen.current != null && Touchscreen.current.primaryTouch.press.isPressed)
        {
            return Touchscreen.current.primaryTouch.position.ReadValue();
        }
        else if (Mouse.current != null && Mouse.current.leftButton.isPressed)
        {
            return Mouse.current.position.ReadValue();
        }

        return Vector2.zero;
    }

    public void SetDefenser(GameObject defenser) {
        this.defenser = defenser;
    }
}
