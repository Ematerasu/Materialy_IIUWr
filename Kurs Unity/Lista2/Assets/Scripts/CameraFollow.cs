using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    public Transform player;

    // Update is called once per frame
    void Update()
    {
        Vector3 player_pos = player.position;
        transform.position = new Vector3(8, 2, player_pos.z);
    }
}
