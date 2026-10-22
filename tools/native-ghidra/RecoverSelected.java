import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
public class RecoverSelected extends GhidraScript {
 public void run() throws Exception { for(String s:getScriptArgs()) { Address a=toAddr(s); disassemble(a); if(getFunctionContaining(a)==null) println("RECOVER "+createFunction(a,null)); } }
}
