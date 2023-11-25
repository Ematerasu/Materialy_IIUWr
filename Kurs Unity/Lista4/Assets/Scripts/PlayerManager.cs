using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerManager : MonoBehaviour
{
    public static PlayerManager instance;
    public int diamondsCounter = 0;
    public int highestScore;
    public int multiplier = 1;

    private void Awake()
    {
        if (instance != null && instance != this)
        {
            Destroy(this);
        }
        else
        {
            instance = this;
        }
    }

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

    public void AddPoint()
    {
        diamondsCounter += multiplier;
    }

    public void ChangeMultiplier(int newValue)
    {
        StartCoroutine(IncreaseMultiplier(newValue, 10f));
    }

    IEnumerator IncreaseMultiplier(int newValue, float seconds)
    {
        multiplier = newValue;
        yield return new WaitForSeconds(seconds);
        multiplier = 1;
        yield return null;
    }
}
