using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CartMovement : MonoBehaviour
{
    public Rigidbody rb;
    private Transform playerTransform;
    // Start is called before the first frame update
    void Start()
    {
        playerTransform = GameObject.FindGameObjectWithTag("Player").transform;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if (transform.position.z - playerTransform.position.z < 36)
            rb.AddForce(0f, 0f, -10f);
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "PowerRail")
        {
            rb.AddForce(0f, 0f, -20f);
        }
    }
}
