#include <gtk/gtk.h>



static void myButtonClicked(GtkWidget *widget, gpointer   data)
{
	    g_print("Button clicked: Hello GTK+\n");
}

int main(int argc, char *argv[])
{
		/*
		 *  LIST OF ITEMS WITHIN THE WINDOW
		 */
		GtkWidget *window;
		
		GtkWidget *myImage;
		GtkWidget *myPaned;
	    GtkWidget *myButton;


		/* 
		 * INSTANCIATES THE WINDOW TO OUR PROGRAM
		 */
	    gtk_init(&argc, &argv);
	    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	    gtk_window_set_default_size(GTK_WINDOW(window), 750, 1250);

		/*
		 * PREPARE OUR PANE
		 */
		myPaned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);

		/*
		 * INITIATES THE REST OF WIDGETS
		 */

		myImage = gtk_image_new_from_file("img/pyramidal.png");
	    myButton = gtk_button_new_with_label("Hello GTK+ from Linux-Buddy");

		/*
		 * LINKS ALL THE WIDGETS WITH IT RESPECTIVE SIGNAL
		 */
		g_signal_connect(myButton, "clicked", G_CALLBACK(myButtonClicked), NULL);
	    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
		
		/*
		 * ADDS THE WIDGETS TO ITS REPECTIVE CONTAINERS
		 */
		gtk_paned_add1(GTK_PANED(myPaned),myImage);
		gtk_paned_add2(GTK_PANED(myPaned),myButton);

	    gtk_container_add(GTK_CONTAINER(window), myPaned);
		/*
		 * CONTROLLS THE WIDGET DISPLAY
		 */

	    //gtk_widget_show(myButton);
		//gtk_widget_show(window);
		gtk_widget_show_all(window);

		// Starts the program properlly
		gtk_main();
		return(0);
}