/*
 * FUN_004b7aa0 at 004b7aa0
 * undefined FUN_004b7aa0(void)
 * Address ranges: 004b7aa0-004b7b44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b7aa0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 1) {
    return 2000;
  }
  DAT_00501110 = param_1;
  DAT_006ab880 = LocalAlloc(0x40,param_1 << 5);
  if (DAT_006ab880 == (HLOCAL)0x0) {
    return 2000;
  }
  if ((param_2 != 2) && (param_2 != 4)) {
    FUN_004afee0(s__s__d____alloc_mem_images___unko_00501134,
                 s_C__libraries_dxdraw_Sprite_cpp_00501114,0xe2,param_2);
  }
  iVar2 = 0;
  if (0 < DAT_00501110) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar1 + (int)DAT_006ab880) = 0;
      *(int *)(iVar1 + 0x18 + (int)DAT_006ab880) = param_2;
      *(undefined4 *)(iVar1 + 0x1c + (int)DAT_006ab880) = 0;
      iVar1 = iVar1 + 0x20;
    } while (iVar2 < DAT_00501110);
  }
  DAT_006ab888 = 1;
  return 0;
}

