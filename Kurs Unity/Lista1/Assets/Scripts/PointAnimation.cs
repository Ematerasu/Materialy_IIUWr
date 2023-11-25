using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PointAnimation : MonoBehaviour
{
    public float rotationStrength = 1f;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.Rotate(0, rotationStrength, 0, Space.Self);
    }
}
