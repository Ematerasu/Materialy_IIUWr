using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public Rigidbody Rb;
    public Transform playerTransform;

    public float jumpForce = 10f;

    // Update is called once per frame
    void FixedUpdate()
    {
        playerTransform.rotation = playerTransform.rotation * Quaternion.Euler(-1.0f, 0.0f, 0.0f);

        if (Input.GetKey(KeyCode.Space) || Input.GetKey(KeyCode.Mouse0))
        {
            this.Rb.AddForce(0, jumpForce, 0);
            playerTransform.rotation = playerTransform.rotation * Quaternion.Euler(5.1f, 0.0f, 0.0f);
        }

        if (this.transform.position.y > 6.3f || this.transform.position.y < -2.3f){
            this.enabled = false;
            FindObjectOfType<GameManager>().EndGame();
        }
    }
}
