/*
 * FUN_0046e554 at 0046e554
 * char __register FUN_0046e554(int param_1)
 * Address ranges: 0046e554-0046e595
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char FUN_0046e554(int param_1)

{
  MCIERROR MVar1;
  undefined1 auStack_18 [4];
  char local_14;
  undefined4 local_10;
  
  *(undefined4 *)(param_1 + 0x2d0) = 0x102;
  local_10 = 4;
  MVar1 = mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x814,0x102,(DWORD_PTR)auStack_18);
  *(MCIERROR *)(param_1 + 0x2ec) = MVar1;
  return local_14 + -0xc;
}

