/*
 * FUN_0041ecc0 at 0041ecc0
 * undefined FUN_0041ecc0(void)
 * Address ranges: 0041ecc0-0041ee0f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0041ecc0(int *param_1,LPCSTR param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  
  cVar1 = (**(code **)(*param_1 + 4))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x10))();
    return 0;
  }
  uVar2 = FUN_0041e440(param_2);
  if ((char)uVar2 == '\0') {
    FUN_004015a6((byte *)s__s__d____Error_getting_dims_of___00436fa8);
    (**(code **)(*param_1 + 0x10))();
    return 0;
  }
  cVar1 = (**(code **)(*param_1 + 8))(uStack_210,uStack_20c);
  if (cVar1 == '\0') {
    FUN_004015a6((byte *)s__s__d____Error_creating_surface_f_00436f80);
    (**(code **)(*param_1 + 0x10))();
    return 0;
  }
  MultiByteToWideChar(0,0,param_2,-1,(LPWSTR)&uStack_210,0x104);
  iVar3 = (**(code **)(**(int **)((int)param_1 + 9) + 0x40))
                    (*(int **)((int)param_1 + 9),&uStack_210,0);
  if (iVar3 < 0) {
    (**(code **)(*param_1 + 0x10))();
    FUN_0040187a((byte *)s__s__d__Failed_to_open_movie__s_00436f60);
    return 0;
  }
  cVar1 = (**(code **)(*param_1 + 0xc))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x10))();
    FUN_0040187a((byte *)s__s__d__Error_finalizing_video_fo_00436f38);
    return 0;
  }
  *(undefined1 *)(param_1 + 1) = 1;
  return 1;
}

