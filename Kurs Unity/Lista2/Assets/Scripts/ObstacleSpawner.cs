using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class ObstacleSpawner : MonoBehaviour
{
    public PlayerScore score;
    public Transform SpawnPoint;
    public GameObject[] Obstacles;

    void Start()
    {
        InvokeRepeating("SpawnObstacle", 0.1f, 3f);
    }

    private void SpawnObstacle()
    {
        int n = (int)Random.Range(0.0f, 7.0f);
        var prefab = Obstacles[n];
        GameObject newObstacle = Instantiate(prefab, SpawnPoint.position, Quaternion.identity);
        newObstacle.GetComponent<Rigidbody>().AddForce(0f, 0f, -10000000f);
    }
}
