from django import forms
from django.forms import ModelForm
from .models import *

class spellForm(forms.ModelForm):
    class Meta:
        model = Spell
        fields = ['sp_name', 'sp_slotlevel', 'sp_range', 'sp_castingtype', 'sp_effect', 'sp_die']

class charForm(forms.Form):
    u_name = forms.CharField(label='u_name')
    pc_name = forms.CharField(label='pc_name')
    pc_class = forms.CharField(label='pc_class')
    pc_level = forms.IntegerField(label='pc_level')
    bg_race = forms.CharField(label='bg_race')
    bg_age = forms.IntegerField(label='bg_age')
    bg_alignment = forms.CharField(label='bg_alignment')