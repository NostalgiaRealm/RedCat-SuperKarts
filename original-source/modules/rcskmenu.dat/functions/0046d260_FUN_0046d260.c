/*
 * FUN_0046d260 at 0046d260
 * undefined __register FUN_0046d260(int param_1)
 * Address ranges: 0046d260-0046d280
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046d260(int param_1)

{
  int *piVar1;
  
  if (*(char *)(param_1 + 0x2c9) == '\0') {
    piVar1 = FUN_0040ad20((int *)&DAT_0046bd88,'\x01',(undefined4 *)PTR_PTR_0047c720);
    FUN_00403604(piVar1);
  }
  return;
}

