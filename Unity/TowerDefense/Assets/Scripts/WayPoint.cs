using Unity.VisualScripting;
using UnityEngine;

public class WayPoint : MonoBehaviour
{
    [SerializeField]
    private GameObject nextWayPoint;

    public GameObject GetNextWayPoint() {
        return nextWayPoint;
    }

    public void SetNextWayPoint(GameObject wayPoint) {
        nextWayPoint = wayPoint;
    }
}
