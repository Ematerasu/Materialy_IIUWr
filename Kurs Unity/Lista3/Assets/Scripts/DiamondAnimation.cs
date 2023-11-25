using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DiamondAnimation : MonoBehaviour
{
    public float rotationStrength;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        transform.Rotate(0f, rotationStrength, 0f);
    }
}
