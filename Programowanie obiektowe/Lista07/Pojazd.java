package com.company;

import java.io.Serializable;
import java.io.SerializablePermission;

public abstract class Pojazd implements Serializable
{
    private static final long serialVersionUID = 0001L;
    String rocznik;
    abstract String ToString();
}
