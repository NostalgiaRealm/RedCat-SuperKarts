/*
 * FUN_0046e03c at 0046e03c
 * undefined __register FUN_0046e03c(int param_1)
 * Address ranges: 0046e03c-0046e067
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e03c(int param_1)

{
  undefined1 auStack_c [8];
  
  FUN_0046d260(param_1);
  mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x807,0x102,(DWORD_PTR)auStack_c);
  return;
}

