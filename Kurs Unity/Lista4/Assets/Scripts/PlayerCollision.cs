using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCollision : MonoBehaviour
{
    public PlayerMovement movement;
    public PlayerManager manager;
    public GameObject gameOverText;
    public GameObject scoreUI;
    public AudioSource audio;
    public AudioSource damage;

    public Material deathMaterial;
    public GameObject skin;

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.tag == "Obstacle")
        {
            movement.enabled = false;
            audio.Stop();
            damage.Play();
            skin.GetComponent<SkinnedMeshRenderer>().material = deathMaterial;
            transform.SetPositionAndRotation(new Vector3(transform.position.x, 1f, transform.position.z), Quaternion.Euler(0f, 0f, -90f));
            scoreUI.SetActive(false);
            gameOverText.SetActive(true);
        }
        if (collision.collider.tag == "Slime")
        {
            movement.Jump();
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Point")
        {
            PlayerManager.instance.AddPoint();
            Destroy(other.gameObject);
        }
        else if (other.gameObject.tag == "Bonusx2")
        {
            PlayerManager.instance.ChangeMultiplier(2);
            PlayerManager.instance.AddPoint();
            Destroy(other.gameObject);
        }
    }
}
