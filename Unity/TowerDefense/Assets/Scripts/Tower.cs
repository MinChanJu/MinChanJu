using TMPro;
using UnityEngine;

public class Tower : MonoBehaviour
{
    [SerializeField]
    public int maxHp = 100;

    [SerializeField]
    private GameObject currentHp;

    [SerializeField]
    private TextMeshProUGUI hpText;

    public int hp;


    private Vector3 fixedSize;

    void Start()
    {
        fixedSize = GameManager.instance.fixedSize;
        hp = maxHp;
    }
    
    private void OnTriggerEnter2D(Collider2D other) {
        if (other.gameObject.tag == "Monster") {
            Monster monster = other.gameObject.GetComponent<Monster>();
            hp -= monster.damage;

            currentHp.transform.localScale = new Vector3(hp/(float) maxHp, 1, 1);
            hpText.SetText(hp.ToString());

            if (hp <= 0) {
                GameManager.instance.GameFinish();
                Destroy(gameObject);
            }
        }
    }
}
