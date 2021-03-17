#include <gtk/gtk.h>
#include <stdio.h>
FILE *fp;
GtkWidget *text;

void writer1 (GtkWidget *wid, gpointer ptr)
{
    fp = fopen ("/home/pi/Desktop/GUItest.txt", "ab");

    if (fp)
    { 
        const char *input  = gtk_entry_get_text (GTK_ENTRY (text));
        fprintf(fp, input);
	fprintf(fp, "\n");
        fclose(fp);
    }
}
void clear (GtkWidget *wid, gpointer ptr)
{
    gtk_entry_set_text (GTK_ENTRY(text), "");
}
void end (GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit();
    fclose(fp);    
}
int main (int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *close = gtk_button_new_with_label ("Close Window");
    GtkWidget *save = gtk_button_new_with_label ("Enter Line");
    GtkWidget *cls = gtk_button_new_with_label ("Clear text Box");
    text = gtk_entry_new();

    g_signal_connect (close, "clicked", G_CALLBACK (end), NULL);
	g_signal_connect (win, "delete_event", G_CALLBACK (end), NULL);
    g_signal_connect (save, "clicked", G_CALLBACK (writer1), NULL);
    g_signal_connect (cls, "clicked", G_CALLBACK (clear), NULL);

    GtkWidget *box = gtk_vbox_new (FALSE, 5);
    gtk_window_set_default_size (GTK_WINDOW (win), 600, 400);
    gtk_box_pack_start (GTK_BOX (box), text, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), save, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), cls, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), close, TRUE, TRUE, 0);

    gtk_container_add (GTK_CONTAINER (win), box);
    gtk_widget_show_all (win);
    gtk_main();
    return 0;
}
