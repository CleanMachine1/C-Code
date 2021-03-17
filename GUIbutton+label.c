#include <gtk/gtk.h>

int count = 0;
GtkWidget *txt;

void text (GtkWidget *wid, gpointer ptr)
{
    const char *input = gtk_entry_get_text (GTK_ENTRY (txt));
    gtk_label_set_text (GTK_LABEL (ptr), input);
}
void end (GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit ();
}
void countbutton (GtkWidget *wid, gpointer ptr)
{
    char buffer[255];
    count++;
    sprintf(buffer, "Button has been pressed %d times", count);
    gtk_label_set_text (GTK_LABEL (ptr), buffer);
}

void best (GtkWidget *wid, gpointer ptr)
{
    char buffer1[30];
    sprintf(buffer1, "You're the best!");
    gtk_label_set_text (GTK_LABEL (ptr), buffer1);
}
int main (int argc, char *argv[])
{
    gtk_init (&argc, &argv);
	GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *close = gtk_button_new_with_label ("Close Window");
    g_signal_connect (close, "clicked", G_CALLBACK (end), NULL);
	g_signal_connect (win, "delete_event", G_CALLBACK (end), NULL);
    GtkWidget *label = gtk_label_new ("Basic GUI");
    GtkWidget *label1 = gtk_label_new ("");
    GtkWidget *label2 = gtk_label_new ("");
    GtkWidget *coplbl = gtk_label_new ("");
    GtkWidget *cop = gtk_button_new_with_label ("Copy Button");

    g_signal_connect (cop, "clicked", G_CALLBACK (text), coplbl);
    txt = gtk_entry_new();
    GtkWidget *coun = gtk_button_new_with_label ("Counter :)");
    GtkWidget *bes = gtk_button_new_with_label ("Gratitude ;)");
    g_signal_connect (bes, "clicked", G_CALLBACK (best), label2);
    g_signal_connect (coun, "clicked", G_CALLBACK (countbutton), label1);
    GtkWidget *box = gtk_vbox_new (FALSE, 5);

    gtk_box_pack_start (GTK_BOX (box), label, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), coun, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), label1, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), bes, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), label2, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), close, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), cop, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), coplbl, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), txt, TRUE, TRUE, 0);    
    gtk_container_add (GTK_CONTAINER (win), box);
    gtk_widget_show_all (win);
    gtk_main ();
    return 0;
}
