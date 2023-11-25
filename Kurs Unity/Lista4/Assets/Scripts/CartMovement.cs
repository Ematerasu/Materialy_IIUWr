using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CartMovement : MonoBehaviour
{
    public Rigidbody rb;
    private Transform playerTransform;
    private float forwardSpeed = 10f;
    // Start is called before the first frame update
    void Start()
    {
        playerTransform = GameObject.FindGameObjectWithTag("Player").transform;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if (-10 < transform.position.z - playerTransform.position.z &&  transform.position.z - playerTransform.position.z < 36)
        {
            if (!GetComponent<AudioSource>().isPlaying)
                GetComponent<AudioSource>().Play();
            rb.AddForce(0f, 0f, -forwardSpeed);
        }

        if (-30 > transform.position.z - playerTransform.position.z)
            Destroy(this.gameObject);
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "PowerRail")
        {
            forwardSpeed = 30f;
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.tag == "Player")
        {
            GetComponent<AudioSource>().Stop();
        }
    }
}
