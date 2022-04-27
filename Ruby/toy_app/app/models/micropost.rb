class Micropost < ApplicationRecord
  belongs_to :user
  validates :context, length: { maximum: 140 }, presence: true
end
