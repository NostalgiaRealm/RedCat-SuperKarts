/*
 * FUN_0046e068 at 0046e068
 * undefined4 __register FUN_0046e068(int param_1, undefined4 param_2)
 * Address ranges: 0046e068-0046e09f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0046e068(int param_1,undefined4 param_2)

{
  undefined1 auStack_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(param_1 + 0x2d0) = 0x112;
  local_8 = 2;
  local_4 = param_2;
  mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x814,0x112,(DWORD_PTR)auStack_10);
  return local_c;
}

