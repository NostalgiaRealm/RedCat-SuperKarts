// Conservatively extend automatic discovery; never invent code from arbitrary bytes.
// @category RedCat.OriginalSource
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

public class RecoverFunctions extends GhidraScript {
    private void clearConflictingOrphan(Address address) throws Exception {
        Listing listing=currentProgram.getListing();
        CodeUnit unit=listing.getCodeUnitContaining(address);
        if(unit!=null&&listing.getInstructionAt(address)==null) {
            FunctionIterator following=currentProgram.getFunctionManager().getFunctions(address,true);
            Function next=following.hasNext()?following.next():null;
            Address end=next==null?address.add(255):next.getEntryPoint().previous();
            if(end.subtract(address)>65535)end=address.add(255);
            clearListing(unit.getMinAddress(),end);
        }
    }
    @Override public void run() throws Exception {
        Path out=Paths.get(getScriptArgs()[0]);Files.createDirectories(out);
        Listing listing=currentProgram.getListing();
        FunctionManager fm=currentProgram.getFunctionManager();
        int initial=fm.getFunctionCount(),created=0;
        try(PrintWriter log=new PrintWriter(Files.newBufferedWriter(out.resolve("function-recovery.tsv"),StandardCharsets.UTF_8))) {
            log.println("address\tevidence\tresult");
            // These named targets are read from the shipped Delphi method tables
            // and byte-validated by export.py, not guessed from nearby code.
            if(getScriptArgs().length>1)for(String line:Files.readAllLines(Paths.get(getScriptArgs()[1]),StandardCharsets.UTF_8)) {
                if(line.startsWith("address\t")||line.isBlank())continue;
                String[] parts=line.split("\t");Address address=toAddr(parts[0]);
                Function f=fm.getFunctionAt(address);
                if(f==null&&fm.getFunctionContaining(address)==null) {
                    // Published metadata proves the entry even when stock
                    // analysis started decoding in adjacent string/table data.
                    clearConflictingOrphan(address);
                    disassemble(address);f=createFunction(address,null);
                    if(f!=null)created++;
                }
                if(f!=null) {
                    if(f.getName().startsWith("FUN_"))f.setName(parts[1],SourceType.ANALYSIS);
                    f.setComment("Named by original Delphi published-method table: "+parts[1]+"; original record "+parts[2]);
                    log.println(address+"\tdelphi_published_method_"+parts[1]+"\tidentified");
                }else log.println(address+"\tdelphi_published_method_"+parts[1]+"\tcreation_rejected_or_inside_existing_function");
            }
            for(int pass=0;pass<3;pass++) {
                TreeMap<Address,String> candidates=new TreeMap<>();
                InstructionIterator instructions=listing.getInstructions(true);
                while(instructions.hasNext()) {
                    Instruction i=instructions.next();
                    if(i.getFlowType().isCall()) for(Address target:i.getFlows()) {
                        if(currentProgram.getMemory().contains(target)&&currentProgram.getMemory().getBlock(target).isExecute())
                            candidates.put(target,"direct_call_from_"+i.getAddress());
                    }
                    if(fm.getFunctionContaining(i.getAddress())==null&&i.toString().equals("PUSH EBP")) {
                        Instruction next=listing.getInstructionAfter(i.getAddress());
                        if(next!=null&&next.getAddress().equals(i.getMaxAddress().next())&&next.toString().equals("MOV EBP,ESP"))
                            candidates.putIfAbsent(i.getAddress(),"orphan_decoded_frame_prologue");
                    }
                    if(fm.getFunctionContaining(i.getAddress())==null) {
                        String instruction=i.toString(),mnemonic=i.getMnemonicString();
                        boolean plausibleEntry=mnemonic.equals("MOV")||mnemonic.equals("LEA")||
                            mnemonic.equals("RET")||mnemonic.equals("JMP")||mnemonic.equals("FLD")||
                            instruction.startsWith("SUB ESP,")||
                            instruction.matches("XOR (EAX|EBX|ECX|EDX|ESI|EDI),\\1")||
                            instruction.matches("PUSH (EAX|EBX|ECX|EDX|ESI|EDI|EBP|0x[0-9a-f]+)");
                        ReferenceIterator refs=currentProgram.getReferenceManager().getReferencesTo(i.getAddress());
                        while(refs.hasNext()) {
                            Reference r=refs.next();
                            if(plausibleEntry&&r.getReferenceType().isData()&&listing.getInstructionContaining(r.getFromAddress())==null)
                                candidates.putIfAbsent(i.getAddress(),"data_reference_from_"+r.getFromAddress());
                        }
                        // A compiler-aligned decoded block after a closed prior
                        // block is a heuristic function seed, kept explicit in
                        // the recovery ledger. Never linearly decode raw bytes.
                        long alignment=currentProgram.getName().equals("rcskmenu.dat")?4:16;
                        if(i.getAddress().getOffset()%alignment==0&&
                           (mnemonic.equals("PUSH")||mnemonic.equals("MOV")||mnemonic.equals("XOR")||
                            mnemonic.equals("LEA")||mnemonic.equals("FLD")||i.toString().startsWith("SUB ESP,"))) {
                            Instruction previous=listing.getInstructionBefore(i.getAddress());
                            if(previous!=null&&previous.getFallThrough()==null&&!previous.getFlowType().isCall()) {
                                long gap=i.getAddress().subtract(previous.getMaxAddress())-1;
                                boolean padding=gap>=0&&gap<=32;
                                for(long n=1;padding&&n<=gap;n++) {
                                    int value=currentProgram.getMemory().getByte(previous.getMaxAddress().add(n))&255;
                                    padding=value==0||value==0x90||value==0xcc;
                                }
                                if(padding)candidates.putIfAbsent(i.getAddress(),"aligned_decoded_block_after_closed_flow");
                            }
                        }
                    }
                }
                int before=created;
                for(Map.Entry<Address,String> item:candidates.entrySet()) {
                    Address address=item.getKey();
                    if(fm.getFunctionContaining(address)!=null)continue;
                    if(listing.getInstructionAt(address)==null) {
                        // Only a direct call is allowed to seed fresh disassembly.
                        if(!item.getValue().startsWith("direct_call"))continue;
                        Address source=toAddr(item.getValue().substring("direct_call_from_".length()));
                        if(fm.getFunctionContaining(source)!=null)clearConflictingOrphan(address);
                        disassemble(address);
                    }
                    if(listing.getInstructionAt(address)==null){log.println(address+"\t"+item.getValue()+"\tno_instruction");continue;}
                    Function f=createFunction(address,null);
                    if(f==null)log.println(address+"\t"+item.getValue()+"\tcreation_rejected");
                    else{created++;log.println(address+"\t"+item.getValue()+"\tcreated");}
                }
                if(created==before)break;
            }
        }
        println("FUNCTION RECOVERY: initial="+initial+" created="+created+" final="+fm.getFunctionCount());
    }
}
