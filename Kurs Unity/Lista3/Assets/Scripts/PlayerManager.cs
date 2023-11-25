using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerManager : MonoBehaviour
{
    public static int diamondsCounter = 0;
    public static int highestScore;

    // Start is called before the first frame update
    void Start()
    {
        diamondsCounter = 0;
        highestScore = PlayerPrefs.GetInt("highscore", 0);
    }

    // Update is called once per frame
    void Update()
    {

    }
}
