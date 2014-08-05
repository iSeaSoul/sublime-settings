# Tools > New Plugin
# Save as signature.py
 
import datetime, getpass
import sublime, sublime_plugin
 
class SignatureCommand(sublime_plugin.TextCommand):
    def run(self, edit):
 
        signature = "%s @ %s" % (getpass.getuser(), datetime.datetime.now().strftime("%Y-%m-%d %H:%M"))

        self.view.run_command("insert_snippet", { "contents":  signature} )
