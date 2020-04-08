semaphore process_customer = 0;
semaphore process_barber = 0;
semaphore process_cutting = 0;
semaphore mutex = 1;

int noofcustomer = 0;
//process for barber
void barber() 
{
	while(true) 
	{
	wait(process_customer); 
	wait(mutex); 
	noofcustomer = noofcustomer - 1;
	signal(process_barber);
	signal(mutex);
	wait_process();
	}
}
//process for customer
void customer() 
{
	wait(mutex); 
	if (noofcustomer < n) 
	{
	noofcustomer = noofcustomer + 1;
	signal(process_customer);
	signal(mutex);
	wait(process_barber); 
	execute_process();
	}
	else 
	{ 
	signal(mutex);
	}
}

wait_process()
{
	waiting(process_cutting);
}
//process to cut hair
execute_process()
{
	get hair cut for some time;
	signal(process_cutting);
}
