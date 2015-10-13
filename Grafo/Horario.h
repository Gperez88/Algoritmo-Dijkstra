#pragma once

//horas de congestionamientos
namespace Hora{
	const int SIETE_AM = 7;
	const int DIEZ_AM = 10;
	const int UNA_PM = 13;
	const int TRES_PM = 15;
	const int CINCO_PM = 17;
	const int OCHO_PM = 20;
}

class Horario
{
private:
	int hora;
	int nivelCongestionamiento;
public:
	Horario(void);
	Horario(int hora, int nivelCongestionamiento);
	virtual ~Horario(void);

	//GETTERS AND SETTERS
	int getHora();
	void setHora(int hora);
	int getNivelCongestionamiento();
	void setNivelCongestionamianto(int nivelCongestionamiento);
};

