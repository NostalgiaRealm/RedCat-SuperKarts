/*
 * FUN_0041ea30 at 0041ea30
 * undefined FUN_0041ea30(void)
 * Address ranges: 0041ea30-0041eb02
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __fastcall FUN_0041ea30(int param_1)

{
  LPVOID *ppv;
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  ppv = (LPVOID *)(param_1 + 9);
  CoCreateInstance((IID *)&DAT_00429fb8,(LPUNKNOWN)0x0,1,(IID *)&DAT_00429fc8,ppv);
  pvVar1 = *ppv;
  if (pvVar1 == (LPVOID)0x0) {
    FUN_004015a6((byte *)s__s__d____Error_creating_stream_o_00436e84);
  }
  iVar2 = (**(code **)(*(int *)*ppv + 0x30))(*ppv,0,1,0);
  if (-1 >= iVar2) {
    FUN_004015a6((byte *)s__s__d____Failed_to_call_Initiali_00436e5c);
  }
  iVar3 = (**(code **)(*(int *)*ppv + 0x3c))(*ppv,DAT_00438414,&DAT_00429fa8,0,0);
  if (-1 >= iVar3) {
    FUN_004015a6((byte *)s__s__d____Failed_adding_primary_v_00436e34);
  }
  iVar4 = (**(code **)(*(int *)*ppv + 0x3c))(*ppv,0,&DAT_00429f98,1,0);
  if (iVar4 < 0) {
    FUN_004015a6((byte *)s__s__d____Failed_adding_primary_s_00436e0c);
    return true;
  }
  return -1 < iVar3 && (-1 < iVar2 && pvVar1 != (LPVOID)0x0);
}

