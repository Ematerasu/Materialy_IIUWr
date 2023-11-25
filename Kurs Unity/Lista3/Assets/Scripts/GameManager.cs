using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public GameObject[] baseLevels;
    public GameObject[] normalLevels;
    public float zSpawn = 36;
    public float levelLength = 36;
    private int numberOfLevels = 5;
    private List<GameObject> activeLevels = new List<GameObject>();
    private int counter = 0;


    public Transform playerTransform;

    void Start()
    {
        for (int i = 0; i < numberOfLevels; i++)
        {
            SpawnLevel(Random.Range(0, baseLevels.Length), baseLevels);
        }
    }


    void Update()
    {
        if (playerTransform.position.z > activeLevels[activeLevels.Count / 2].transform.position.z)
        {
            if (counter < 10)
                SpawnLevel(Random.Range(0, baseLevels.Length), baseLevels);
            else
                SpawnLevel(Random.Range(0, normalLevels.Length), normalLevels);
            DeleteLevel();
        }
    }

    private void SpawnLevel(int idx, GameObject[] levels)
    {
        GameObject obj = Instantiate(levels[idx], transform.forward * zSpawn, transform.rotation);
        zSpawn += levelLength;
        activeLevels.Add(obj);
        counter++;
    }

    private void DeleteLevel()
    {
        Destroy(activeLevels[0]);
        activeLevels.RemoveAt(0);
    }
}
