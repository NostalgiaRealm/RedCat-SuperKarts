/*
 * FUN_00404ec0 at 00404ec0
 * PVOID __register FUN_00404ec0(LPCVOID param_1)
 * Address ranges: 00404ec0-00404ee5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

PVOID FUN_00404ec0(LPCVOID param_1)

{
  _MEMORY_BASIC_INFORMATION local_1c;
  
  VirtualQuery(param_1,&local_1c,0x1c);
  if (local_1c.State != 0x1000) {
    local_1c.AllocationBase = (PVOID)0x0;
  }
  return local_1c.AllocationBase;
}

