#pragma once

using namespace System;
using namespace System::Diagnostics;

ref class Tiempo {
public:
    static Stopwatch^ tiempo = gcnew Stopwatch();

    static void tiempoInicial() {
        tiempo = gcnew Stopwatch();
        tiempo->Start();
    }

    static String^ tiempoFinal() {
        String^ tiempoTotal = "";
        tiempo->Stop();
        TimeSpan TT = tiempo->Elapsed;
        tiempoTotal = TT.TotalMilliseconds.ToString("F2"); 
        return tiempoTotal;
    }

    static String^ tiempoFinalMinutos() {
        String^ tiempoTotal = "";
        tiempo->Stop();
        TimeSpan TT = tiempo->Elapsed;
        tiempoTotal = TT.ToString("mm':'ss");
        return tiempoTotal;
    }
};


