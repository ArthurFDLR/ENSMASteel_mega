class barillet
{
	public:
	
	barillet();
	
	int get_pos();	// obtenir position actuelle
	void set_pos(int pos);	// aller à la position souhaité
	void turn(int nb); // tourner de nb case (+ sens trigo, - sens horraire)
	
	
	private:
	
	int m_pos;
};

class pompe
{
	public:
	
	pompe();
	
	void take(); // prendre un pallet
	void release(); // lacher le pallet
	
	
	private:
	
	bool taken;
}

enum state_elev {UP,DOWN};

class elevator
{
	public:
	
	elevator();
	
	void up(); // faire monter les ventouses
	void down(); // faire descendre les ventouses
	
	
	private:
	state_elev state;
}