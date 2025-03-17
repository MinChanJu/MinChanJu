using UnityEngine;

public class HideInGame : MonoBehaviour
{
    void Start() {
        Renderer objectRenderer = GetComponent<Renderer>();
        objectRenderer.enabled = false;
    }

}
