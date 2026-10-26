/*
 * FUN_0046e0e0 at 0046e0e0
 * undefined __register FUN_0046e0e0(int param_1, byte param_2)
 * Address ranges: 0046e0e0-0046e11b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e0e0(int param_1,byte param_2)

{
  MCIERROR MVar1;
  undefined1 auStack_14 [4];
  uint local_10;
  
  *(undefined4 *)(param_1 + 0x2d0) = 0x401;
  local_10 = (uint)param_2;
  MVar1 = mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x80d,0x401,(DWORD_PTR)auStack_14);
  *(MCIERROR *)(param_1 + 0x2ec) = MVar1;
  return;
}

