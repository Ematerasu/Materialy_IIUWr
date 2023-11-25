using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RotateObject : MonoBehaviour
{
    public float rotationStrength;

    void Update()
    {
        transform.Rotate(0f, rotationStrength, 0f);
    }
}
