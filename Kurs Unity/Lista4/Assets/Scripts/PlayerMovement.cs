using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Video;

public class PlayerMovement : MonoBehaviour
{
    public Rigidbody rb;
    public float forwardSpeed = 0.02f;
    public float jumpForce = 40.0f;
    private int line;
    private bool _canJump = true;
    private bool _canSlide = true;
    public AudioSource audio;
    public Animator animator;


    // Start is called before the first frame update
    void Start()
    {
        line = 0;
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.LeftArrow))
        {
            if (line != -1)
            {
                line -= 1;
            }

        }
        else if (Input.GetKeyDown(KeyCode.RightArrow))
            if (line != 1)
            {
                line += 1;
            }
    }

    private void FixedUpdate()
    {
        transform.position = Vector3.MoveTowards(
                    transform.position,
                    new Vector3(2f * line, transform.position.y, transform.position.z + forwardSpeed * Time.fixedDeltaTime),
                    1.0f
                    );
        if (Input.GetKeyDown(KeyCode.DownArrow) && IsGrounded() && _canSlide)
        {
            StartCoroutine(Slide());
        }
        if (Input.GetKey(KeyCode.UpArrow) && IsGrounded() && _canJump)
        {
            _canJump = false;
            Jump();
        }
    }

    private bool IsGrounded()
    {
        return Physics.Raycast(transform.position, Vector3.down, 1.32f);
    }

    IEnumerator Slide()
    {
        animator.Play("NotMoving");
        audio.Stop();
        _canSlide = false;
        _canJump = false;
        transform.Rotate(-90f, 0f, 0f);
        transform.position = new Vector3(transform.position.x, 1f, transform.position.z);
        yield return new WaitForSeconds(1.2f);
        transform.Rotate(90f, 0f, 0f);
        transform.position = new Vector3(transform.position.x, 1.5f, transform.position.z);
        _canJump = true;
        _canSlide = true;
        animator.Play("SteveRun");
        audio.Play();
    }

    public void Jump()
    {
        StartCoroutine(_Jump());
    }

    IEnumerator _Jump()
    {
        audio.Stop();
        animator.Play("Jump");
        rb.AddForce(Vector3.up * jumpForce, ForceMode.Impulse);
        yield return new WaitForSeconds(1.25f);
        _canJump = true;
        audio.Play();
    }

}
