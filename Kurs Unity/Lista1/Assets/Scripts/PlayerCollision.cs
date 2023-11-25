using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCollision : MonoBehaviour
{
    public PlayerMovement movement;
    public PlayerScore score;

    void OnCollisionEnter(Collision collisionInfo)
    {
        if (collisionInfo.collider.tag == "Obstacle"){
            movement.enabled = false;
            FindObjectOfType<GameManager>().EndGame();
        }

    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Point")
        {
            PlayerScore.IncrementScore();
            other.gameObject.SetActive(false);
        }
            
    }
}
