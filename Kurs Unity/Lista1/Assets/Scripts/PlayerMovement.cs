using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public Rigidbody Rb;

    public float forwardForce = 1000f;
    public float turnForce = 1000f;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void FixedUpdate()
    {
        this.Rb.AddForce(0, 0, this.forwardForce * Time.deltaTime);

        if (Input.GetKey("d")){
            this.Rb.AddForce(this.turnForce * Time.deltaTime, 0, 0);
        }
        else if (Input.GetKey("a")){
            this.Rb.AddForce(-this.turnForce * Time.deltaTime, 0, 0);
        }

        if (Rb.position.y < -2.0f)
        {
            FindObjectOfType<GameManager>().EndGame();
        }
    }
}
